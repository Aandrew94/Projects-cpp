#include    <iostream>
#include    <array>

int main(){

    int choice{};
    int item{};
    size_t count{};

    std::array<int , 5> arr;
    arr.fill(0);
    std::array<int , 5>::iterator it;

    while(1){
        std::cout<< "\n---------------------" << '\n';
        std::cout<< "Array Implementation in Stl" << '\n';
        std::cout<< "\n---------------------" << '\n';
        std::cout<< "1.Insert Element into the Array" << '\n';
        std::cout<< "2.Size of the array" << '\n';
        std::cout<< "3.Max size of array" << '\n';
        std::cout<< "4.Front Element of Array" << '\n';
        std::cout<< "5.Back Element of Array" << '\n';
        std::cout<< "6.Display elements of the Array" << '\n';
        std::cout<< "7.Exit" << '\n';

        std::cout<< "Enter your Choice: \t";
        std::cin >> choice;
        switch (choice){
            case 1: 
                std::cout<< "Enter value to be inserted:\t";
                std::cin >> item;
                arr.at(count) = item;
                count++;
            break;

            case 2:
                std::cout<< "Size of array:\n";
                std::cout<< arr.size() <<'\n';
            break;

            case 3:
                std::cout<< "Max size of array\n";
                std::cout<< arr.max_size() << '\n';
            break;

            case 4:
                std::cout<< "Front element of array:\n";
                std::cout<< arr.front() << '\n';
            break;

            case 5:
                std::cout<< "Back element of array:\n";
                std::cout<< arr.back() <<'\n';
            break;

            case 6:
                std::cout<< "Display elements of the array:\n";
                for(it = arr.begin(); it != arr.end(); it++){
                    std::cout<< *it << '\t';
                }
                std::cout<< '\n';
            break;

            case 7:
                exit(1);
            break;
            
            default:
                std::cout<< "Wrong choice\n";
            break;
        }
    }

return 0;
}
