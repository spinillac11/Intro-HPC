#include <iostream>
#include <vector>

void print_v0(const std::vector<double> & mydata); // & para no crear copias y const para no dar permisos de modificacion
void print_v1(const std::vector<double> & mydata);

int main(void){
    std::vector<double> data = {0.1, 0.5, -0.6};

    print_v0(data);
    print_v1(data);

    return 0;
}

void print_v0(const std::vector<double> & mydata){
    
    for (int ii = 0; ii < mydata.size(); ii++)
    {
        std::cout << mydata[ii] << " ";
    }
    std::cout << "\n";
}

void print_v1(const std::vector<double> & mydata){

    // For automatico: para rrecorer automaticamente un array
    for (auto& ii : mydata) // & para referenciar la memoria del dato y poder modificar el array
    {
        std::cout << ii << " ";
    }
    std::cout << "\n";
}