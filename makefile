wordcount: wordcount.cpp
	clang++ -std=c++11 wordcount.cpp -o wordcount
clean:
	rm -f wordcount