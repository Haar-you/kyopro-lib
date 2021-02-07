#!/usr/bin/env ruby

require "optparse"
require "open3"
require "fileutils"
require "pathname"

opts = OptionParser.new

$exec_only = false
$compile_only = false

$debug = true
$cpp_version = "c++1z"

$use_atcoder_lib = false
$atcoder_lib_path = nil

$use_boost = false
$boost_path = nil

$sanitize = false

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

opts.on("--boost"){
  $use_boost_lib = true
  $boost_path = ENV["BOOST_PATH"]
}

opts.on("--sanitize"){
  $sanitize = true
}

$mylib = Pathname.new(__dir__).parent

opts.parse!(ARGV)
source_file, input_file = ARGV

if not $exec_only
  STDERR.puts "\e[33;1m bundling ... \e[m"
  bundled_file = "#{source_file}.bundle.cpp"
  o, e, s = Open3.capture3("oj-bundle #{source_file} -I #{$mylib} > #{bundled_file}")

  unless s.success?
    STDERR.print e
    exit(1)
  end

  STDERR.puts "\e[33;1m compiling ... \e[m"

  cmd = [
    "g++",
    "#{source_file}",
    "-O2",
    "-std=#{$cpp_version}",
    "-Wall",
    "-Wextra",
    "-I#{$mylib}",
    $debug ? "-DDEBUG" : "",
    $debug ? "-D_GLIBCXX_DEBUG" : "",
    ($debug and $sanitize) ? "-fsanitize=undefined" : "",
    $debug ? "-g" : "",
    $use_boost ? "-I#{$boost_path}" : "",
    $use_atcoder_lib ? "-I#{$atcoder_lib_path}" : "",
    "-o a.out"
  ]

  STDERR.puts cmd.join(" ")

  o, e, s = Open3.capture3(cmd.join(" "))

  print o
  STDERR.print e

  exit(1) unless s.success?

  STDERR.puts "\e[33;1m compiled \e[m"
end

if not $compile_only
  if input_file.nil?
    system("./a.out")
  else
    system("./a.out < #{input_file}")
  end
end
