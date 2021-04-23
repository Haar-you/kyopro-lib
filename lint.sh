for path in $(find ./Mylib/ -name "*.cpp");
do
    echo $path
    clang-format $path -i
done

for path in $(find ./test/ -name "*.cpp");
do
    echo $path
    clang-format $path -i
done
