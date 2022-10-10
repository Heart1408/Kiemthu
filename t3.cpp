#include <iostream>
using namespace std;

class Product {
  private:
    string name;
    int amount;
    int price;

  public:
    void setProduct(string n, int a, int p) {
      name = n;
      amount = a;
      price = p;
    }
    
    string getName() {
      return name;
    }
     
    int getAmount() {
      return amount;
    }
    
    int getPrice() {
    	return price;
	}
};

void output(Product P[]) {
	int T, n;
	
	cout << "\n Nap tien: ";
	cin >> T;
	
	if (T < 8000) 
		throw "\n So du khong du de mua san pham.";
		
	cout << "\n Nhap so thu tu de mua hang: ";
	cin >> n;
	
	if (n < 0 || n > 4) {
		throw "\n Ma san pham khong hop le!";
	} else if ( P[n-1].getAmount() == 0) {
		throw "\n San pham dang tam het hang.";
	} else if (P[n-1].getPrice() > T) {
		throw "\n So du khong du de mua san pham." ;
	}
	
	cout << "\n" << P[n-1].getName() << ", " << T - P[n-1].getPrice();
}

int main() {
  Product P[4];
  P[0].setProduct("Tra xanh 0 do", 4, 20000);
  P[1].setProduct("Sting", 5, 15000);
  P[2].setProduct("Sua tuoi", 0, 10000);
  P[3].setProduct("Nuoc suoi", 8, 8000);
  
  cout << "Danh sach san pham:";
  for (int i = 0 ; i< 4; i++) {
  	cout << "\n" << i << ". " << P[i].getName();
  }
  
  try {
  	output (P);
  } catch (const char* msg) {
     cerr << msg << endl;
   }
   
  return 0;
}

