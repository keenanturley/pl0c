# Clean output directory
rm -f ./tests/out/*

for test in ./tests/in/*.in
do
  TMP=${test/in/out}
  ./src/compile -l -a -v $test > ${TMP%in}out
done

echo "Tests Complete!"
