#include <iostream>
#include <list>
    
int main(){
        
    int myints[] = {5, 6, 3, 2, 7};
    std::list<int> l, l1 (myints, myints + sizeof(myints) / sizeof(int));
    std::list<int>::iterator it;

    int choice{};
    int  item{};
    
    while(1){
        std::cout<<"\n---------------------" << '\n';
        std::cout<<"List Implementation in Stl" << '\n';
        std::cout<<"\n---------------------" << '\n';
        std::cout<<"1.Insert Element at the Front" << '\n';
        std::cout<<"2.Insert Element at the End" << '\n';
        std::cout<<"3.Delete Element at the Front" << '\n';
        std::cout<<"4.Delete Element at the End" << '\n';
        std::cout<<"5.Front Element of List" << '\n';
        std::cout<<"6.Last Element of the List" << '\n';
        std::cout<<"7.Size of the List" << '\n';
        std::cout<<"8.Resize List" << '\n';
        std::cout<<"9.Remove Elements with Specific Values" << '\n';
        std::cout<<"10.Remove Duplicate Values" << '\n';
        std::cout<<"11.Reverse the order of elements" << '\n';
        std::cout<<"12.Sort Forward List" << '\n';
        std::cout<<"13.Merge Sorted Lists" << '\n';
        std::cout<<"14.Display Forward List" << '\n';
        std::cout<<"15.Exit" << '\n';
        std::cout<<"Enter your Choice:\t";
        std::cin >>choice;

        switch(choice){
            case 1:
                std::cout<<"Enter value to be inserted at the front: ";
                std::cin >>item;
                l.push_front(item);
            break;

            case 2:
                std::cout<<"Enter value to be inserted at the end: ";
                std::cin>>item;
                l.push_back(item);
            break;

            case 3:
                item = l.front();
                l.pop_front();
    	        std::cout<<"Element "<<item<<" deleted"<< '\n';

            break;

            case 4:
                item = l.back();
                l.pop_back();
    	        std::cout<<"Element "<<item<<" deleted"<<'\n';
            break;

            case 5:
    	        std::cout<<"Front Element of the List: ";
    	        std::cout<<l.front()<<'\n';
            break;

            case 6:
                std::cout<<"Last Element of the List: ";
                std::cout<<l.back()<<'\n';
            break;

            case 7:
                std::cout<<"Size of the List: "<<l.size()<<'\n';
            break;

            case 8:
                std::cout<<"Enter new size of the List: ";
                std::cin>>item;
                if (item <= l.size())
                    l.resize(item);
                else
                    l.resize(item, 0);
            break;

            case 9:
                std::cout<<"Enter element to be deleted: ";
                std::cin>>item;
                l.remove(item);
            break;

            case 10:
                l.unique();
                std::cout<<"Duplicate Items Deleted"<<'\n';
            break;

            case 11:
                l.reverse();
                std::cout<<"List reversed"<<'\n';
            break;

            case 12:
                l.sort();
                std::cout<<"List Sorted"<<'\n';
            break;
            
            case 13:
                l1.sort();
                l.sort();
                l.merge(l1);
                std::cout<<"Lists Merged after sorting"<<'\n';
            break;

            case 14:
                std::cout<<"Elements of the List:  ";
                for (it = l.begin(); it != l.end(); it++)
                    std::cout<<*it<<"  ";
                std::cout<<std::endl;
            break;

        	case 15:
                exit(1);
    	    break;

            default:
                std::cout<<"Wrong Choice"<<std::endl;
            break;
            }
        }
    return 0;
}