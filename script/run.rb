#!/usr/bin/env ruby

require "optparse"
require "open3"
require "fileutils"
require "pathname"

opts = OptionParser.new

$exec_only = false
$debug = true
$cpp_version = "c++1z"
$boost = nil
$compile_only = false
$use_atcoder_lib = false

opts.on("-e", "--exec-only"){
  $exec_only = true
}

opts.on("--no-debug"){
  $debug = false
}

opts.on("--cpp VERSION"){|version|
  $cpp_version = version
}

opts.on("-c", "--compile-only"){
  $compile_only = true
}

opts.on("--atcoder"){
  $use_atcoder_lib = true
  $atcoder_lib_path = ENV["ATCODER_LIB_PATH"]
}

$mylib = Pathname.new(__dir__).parent

opts.parse!(ARGV)
source_file, input_file = ARGV

if not $exec_only
  puts "\e[33;1m compiling ... \e[m"

  cmd = [
    "g++",
    "#{source_file}",
    "-O2",
    "-std=#{$cpp_version}",
    "-Wall",
    "-Wextra",
    "-I#{$mylib}",
    $boost.nil? ? "" : "-I#{$boost}",
    $debug ? "-DDEBUG" : "",
    $debug ? "-D_GLIBCXX_DEBUG" : "",
    #"-fsanitize=undefined",
    $debug ? "-g" : "",
    $use_atcoder_lib ? "-I#{$atcoder_lib_path}" : "",
    "-o a.out"
  ]

  puts cmd.join(" ")

  o, e, s = Open3.capture3(cmd.join(" "))

  print o
  print e

  exit(1) unless s.success?

  puts "\e[33;1m compiled \e[m"
end

if not $compile_only
  if input_file.nil?
    system("./a.out")
  else
    system("./a.out < #{input_file}")
  end
end
