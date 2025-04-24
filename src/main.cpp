/* Amerike university
      Author: Julio López
      Date: 22/04/25
      Practice #: 23
      Description: This program shall be a sort of bank account system that allows the user to take out or add a amount of money*/
 
      #include <iostream>
      #include <string>
      
      using namespace std;
      
      #include <iostream>
      #include <string>
      
      using namespace std;
      
      class Bank_info {
      private:
          string Owner;
          string Account; 
          double Funds;
      
      public:
          Bank_info(string Owner, string Account, double Funds1) 
          {
            this->Owner = Owner;
            this->Account = Account;
            this->Funds = Funds1;
          }
          string getOwner() 
          {
           return Owner;
          }
          string getAccount()
          {
            return Account;
          }
          double getFunds()
          {
            return Funds;
          }
    
          void setOwner(string O)
          {
            Owner = O;
          }
          void setAccount(string Type)
          {
            Account = Type;
          }
          void setFunds(double F) 
        {
            Funds = F; 
        }
      
          void Add(double Amount) 
          {
              if (Amount > 0) {
                  Funds += Amount;
                  CheckFunds();
              } else {
                  cout << "Cant add amount" << "\n";
              }
          }
      
          void CheckFunds(){
              cout << "Funds: " << getFunds() << endl;
          }
      
          void Withdraw(double Amount)
          {
            if (Account == "Checks")
            {
                  cout << "Cant withdraw from a check" << "\n";
              } else if (Amount > Funds) 
              {
                  cout << "Not enough Funds" << "\n";
              } else 
              {
                  Funds -= Amount;
                  CheckFunds();
              }
          }
      
          void Check(){
              cout << "Owner: " << Owner << ", Type: " << Account << endl;
          }
      };
      
      int main() {
          string Name;
          string Type;
          double Funds1;
      
          cout << "New account" << "\n";
          cout << "Owner: ";
          cin >> Name;
      
          cout << "Type of account (Savings, Checks, Roster): ";
          cin >> Type;
      
          cout << "Add funds: ";
          cin >> Funds1;
      
          Bank_info Account(Name, Type, Funds1);
      
          char Key;
          do {
              cout << "BANK OF YOUR CHOICE" << "\n";
              cout << "See funds (1)" << "\n";
              cout << "Add funds (+)" << "\n";
              cout << "Withdraw funds (-)" << "\n";
              cout << "See owner and account type (?)" << "\n";
              cout << "Exit (X)" << "\n";
              cin >> Key;
      
              switch (Key){
                  case 1:
                      Account.CheckFunds();
                      break;
                  case '+':{
                      double In;
                      cout << "How much?: ";
                      cin >> In;
                      Account.Add(In);
                      break;
                  }
                  case '-':{
                      double Draw;
                      cout << "How much?: ";
                      cin >> Draw;
                      Account.Withdraw(Draw);
                      break;
                  }
                  case '?':
                      Account.Check();
                      break;
                  case ',':
                      cout << "Exiting" << "\n";
                      break;
                  default:
                      cout << "Invalid, try again" << "\n";
              }
      
          } while (Key != 0);
      
          return 0;
      }
      