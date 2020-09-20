#include    <iostream>

int main(){


    std::string text{};
    std::cout<< "Get text:\t";
    std::getline(std::cin,text);

    for(size_t i=0; i<text.length();i++){
        std::cout<< static_cast<int>(text[i]) << " ";
    }

    std::cout<<'\n';
    return 0;
}