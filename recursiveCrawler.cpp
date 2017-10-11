#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
namespace nr = boost::filesystem;

void recursiveCrawler(const nr::path &inputDir){
	if(!nr::is_directory(inputDir)) {
		std::cout << inputDir << "This is not a valid directory ";
	}
	
	nr::directory_iterator end_itr;
	for(nr::directory_iterator dir_itr(inputDir); dir_itr != end_itr; dir_itr++){
		if(nr::is_regular_file( dir_itr->status() )){
			std::cout<< "\n" << dir_itr->path() << "\n";
		}
		if(nr::is_directory(dir_itr->status())){
			recursiveCrawler(dir_itr->path() );
		}
	}
			
}

int main(int argc, char *argv[]) {
	std::string inputDirectoy;
	std::cout << "Please enter the directory: ";
	std::cin >>  inputDirectoy;
	nr::path p(inputDirectoy);
	recursiveCrawler(p);
}
