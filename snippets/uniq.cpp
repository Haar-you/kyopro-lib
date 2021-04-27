# -*- mode: snippet -*-
# name: uniq
# key: uniq
# --
$1.erase(std::unique($1.begin(), $1.end()), $1.end());