#include    <iostream>
#include    <map>

int main(){
    
    std::map<int, std::string> Employee;
    std::map<int, std::string>::iterator it;
    int choice{}, item{};
    std::string str_item{};
    
    while (1){
        std::cout<<"\n---------------------" << '\n';
        std::cout<<"Map Implementation in Stl" << '\n';
        std::cout<<"\n---------------------" << '\n';
        std::cout<<"1.Insert Element into the Map" << '\n';
        std::cout<<"2.Delete Element of the Map" << '\n';
	    std::cout<<"3.Size of the Map" << '\n';
        std::cout<<"4.Find Element at a key in Map" << '\n';
        std::cout<<"5.Dislplay by Iterator" << '\n';
        std::cout<<"6.Count Elements at a specific key" << '\n';
        std::cout<<"7.Exit" << '\n';
        std::cout<<"Enter your Choice:" << '\n';
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout<< "Enter the key-value to be inserted:\n";
                std::cin >> item;
                std::cout<< "Enter the value associated with the " << item << " key\n";
                std::cin >> str_item;
                Employee.insert(std::pair<int, std::string> (item , str_item) );
            break;
            
            case 2:
                std::cout<< "Enter the key-value to be deleted:\n";
                std::cin >> item;
                Employee.erase(item);
            break;

            case 3:
                std::cout<<"Size of Map:\t" << Employee.size() << '\n';
            break;

            case 4:
                std::cout<< "Enter the key you want to find:\n";
                std::cin >> item;              
                if ( Employee.count(item) != 0){
                    std::cout<< Employee.find(item)->first << ":" << Employee.find(item)->second << '\n';
                }
                else{
                    std::cout<< "No element found\n"; 
                }
            break;

            case 5:
                std::cout << "Display by iterator:\n";
                for(it = Employee.begin(); it != Employee.end(); it++){
                    std::cout<< it->first << ":" << (*it).second << '\n';
                }    
            break;

            case 6:
                std::cout << "Enter key to count:\n";
                std::cin >> item;
                std::cout << Employee.count(item) << "\n\n";
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