require "fileutils"

Dir.glob("../Mylib/**/*.cpp").each do |fp|
  contents = []

  File.open(fp, "r") do |f|
    f.each do |line|

      if line =~ /#pragma once/
        next
      elsif line =~ /#include (.*)/
        include_fp = $1

        if include_fp !~ /<boost\/.*>/
          next
        end
      end

      contents << line
    end
  end

  path = fp.gsub(/.*Mylib\//, "").gsub("/", "__")

  name = path.gsub(".cpp", "")
  key = name

  Dir.mkdir("snippet") unless Dir.exist?("snippet")

  File.open("snippet/#{path}", "w") do |f|

    f.write <<EOS
# -*- mode: snippet -*-
# name: #{name}
# key: #{key}
# --

EOS
    
    contents.each do |line|
      f.write line
    end
  end
end
