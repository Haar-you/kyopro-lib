#!/usr/bin/env ruby
# coding: utf-8

require "optparse"
require "open3"
require "fileutils"
require "pathname"

opts = OptionParser.new

$exec_only = false
$debug = true
$cpp_version = "c++1z"
$boost = nil

$not_compile_main = false
$not_compile_server = false

opts.on("-e", "--exec-only"){
  $exec_only = true
}

opts.on("--no-debug"){
  $debug = false
}

opts.on("--cpp VERSION"){|version|
  $cpp_version = version
}

opts.on("--nm", "--not-compile-main"){
  $not_compile_main = true
}

opts.on("--ns", "--not-compile-server"){
  $not_compile_server = true
}

$mylib = Pathname.new(__dir__).parent

opts.parse!(ARGV)
main_file, server_file = ARGV

if not $exec_only and not $not_compile_main
  puts "\e[33;1m compiling #{main_file} ... \e[m"

  cmd = [
    "g++",
    "#{main_file}",
    "-O2",
    "-std=#{$cpp_version}",
    "-Wall",
    "-Wextra",
    "-I#{$mylib}",
    $boost.nil? ? "" : "-I#{$boost}",
    $debug.nil? ? "" : "-DDEBUG",
    "-D_GLIBCXX_DEBUG",
    "-g",
    "-o a.out"
  ]

  puts cmd.join(" ")

  o, e, s = Open3.capture3(cmd.join(" "))

  print o
  print e

  exit unless s.success?
  
  puts "\e[33;1m compiled #{main_file} \e[m"
end

if not $exec_only and not $not_compile_server
  puts "\e[33;1m compiling #{server_file} ... \e[m"

  cmd = [
    "g++",
    "#{server_file}",
    "-O2",
    "-std=#{$cpp_version}",
    "-Wall",
    "-Wextra",
    "-I#{$mylib}",
    $boost.nil? ? "" : "-I#{$boost}",
    $debug.nil? ? "" : "-DDEBUG",
    "-D_GLIBCXX_DEBUG",
    "-g",
    "-o server"
  ]

  puts cmd.join(" ")

  o, e, s = Open3.capture3(cmd.join(" "))

  print o
  print e

  exit unless s.success?
  
  puts "\e[33;1m compiled #{server_file} \e[m"
end

system("mkfifo fifo") unless FileTest.exist?("fifo")
system("mkfifo out1") unless FileTest.exist?("out1")
system("mkfifo out2") unless FileTest.exist?("out2")

begin
  # 参考: https://qiita.com/ktateish/items/d350e359d921d174fc28
  
  t = Thread.new do
    system("sed -e 's/^/[\e[34;1m Client \e[m] /' < out1 & sed -e 's/^/[\e[32;1m Server \e[m] /' < out2; wait")
  end

  system(<<EOS
./a.out < fifo | tee ./out1 | ./server | tee ./out2 | \
( while read x ; do sleep 0.1s ; echo $x ; done ) > fifo
EOS
        )

  t.join()
  
rescue => e
  puts e
end
