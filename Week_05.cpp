# include <iostream>
using namespace std;
class CoffeeMachineInterface {
    public:
        void chooseFirstSelection(){
            cout << "First Flavour Selected" << endl;
        }
        void chooseSecondSelection(){
            cout << "Second Flavour Selected" << endl;
        }
};

class OldCoffeeMachine {
    public:
        void chooseFirstSelection(){
            cout << "First flavour selected" << endl;
        }
        void chooseSecondSelection(){
            cout << "Second flavour selected" << endl;
        }
};

class CoffeeTouchscreenAdapter : public CoffeeMachineInterface {
    private:
        OldCoffeeMachine* OldVendingMachine;
    public:
        CoffeeTouchscreenAdapter(OldCoffeeMachine* OldVendingMachine){
            OldVendingMachine = OldVendingMachine;
        }
        void FirstSelection(){
            OldVendingMachine -> FirstSelection();
        }
        void SecondSelection(){
            OldVendingMachine -> SecondSelection();
        }
};


int main(){
    CoffeeMachineInterface* machineWithTs = new CoffeeMachineInterface;
    OldCoffeeMachine* oldMachine = new OldCoffeeMachine;
    CoffeeTouchscreenAdapter* TSadapter = new CoffeeTouchscreenAdapter(oldMachine);
    machineWithTs -> chooseFirstSelection();
    TSadapter -> chooseFirstSelection();
    machineWithTs -> chooseSecondSelection();
    TSadapter -> chooseSecondSelection();
    return 0;
}