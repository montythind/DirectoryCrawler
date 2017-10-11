#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <queue>
namespace nr = boost::filesystem;

void nonRecursiveCrawler(std::string inputDir){
	std::queue<nr::path> q;   
    nr::path p(inputDir);
    
    if(!nr::is_directory(p)) {
        std::cout << p << "This is not a valid directory ";
	}
	
	q.push(p);
	while(!q.empty()){
		if (nr::is_directory(p)) {
			nr::directory_iterator end_iter;
			for(nr::directory_iterator dir_itr(q.front()); dir_itr != end_iter; dir_itr++){
				if(nr::is_regular_file( dir_itr->status() )){
					std::cout<< "\n" << dir_itr->path() << "\n";
				}
		
				if(nr::is_directory(dir_itr->status() )){
					q.push(dir_itr->path());
				}
			}	
			q.pop();		
		}	
	}
} 


int main(int argc, char *argv[]) {
	std::string inputDirectoy;
	std::cout << "Please enter the directory: ";
	std::cin >>  inputDirectoy;
    nonRecursiveCrawler(inputDirectoy);
}
