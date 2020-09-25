#include <iostream>
#include <vector>

int main(){
    std::vector<int> ss;
    std::vector<int>::iterator it;

    int choice{}, item{};

    while(1){
        std::cout<<"\n---------------------"<<'\n';
        std::cout<<"Vector Implementation in Stl"<<'\n';
        std::cout<<"\n---------------------"<<'\n';
        std::cout<<"1.Insert Element into the Vector"<<'\n';
        std::cout<<"2.Delete Last Element of the Vector"<<'\n';
        std::cout<<"3.Size of the Vector"<<'\n';
        std::cout<<"4.Display by Index"<<'\n';
        std::cout<<"5.Dislplay by Iterator"<<'\n';
        std::cout<<"6.Clear the Vector"<<'\n';
        std::cout<<"7.Exit"<<'\n';
        std::cout<<"Enter your Choice \t";
        std::cin>>choice;

        switch(choice){
            case 1:
                std::cout<<"Enter value to be inserted: ";
                std::cin>>item;
                ss.push_back(item);
            break;

            case 2:
                std::cout<<"Delete Last Element Inserted:"<< '\n';
                ss.pop_back();
            break;

            case 3:
                std::cout<<"Size of Vector: ";
                std::cout<<ss.size() << '\n';
            break;

            case 4:
                std::cout<<"Displaying Vector by Index: ";
                for (size_t i = 0; i < ss.size(); i++){
                    std::cout<<ss[i]<<'\t';
                }
                std::cout<< '\n';
            break;

            case 5:
                std::cout<<"Displaying Vector by Iterator: ";
                for (it = ss.begin(); it != ss.end(); it++){
                    std::cout<< *it <<'\t';
                }
                std::cout<< '\n';
            break;

            case 6:
                ss.clear();
                std::cout<<"Vector Cleared"<< '\n';
            break;

            case 7:
                exit(1);
            break;

            default:
                std::cout<<"Wrong Choice"<< '\n';
            break;
        }
    }
return 0;
}