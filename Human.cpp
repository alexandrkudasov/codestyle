
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;


class Human {
private:
    string name;
    int height;
    int weight;
    int age;
    double latitude;
    double longitude;
    int x;
    int y;
    double distance;
    int start;
    int speedMax;
    int speedMin;
    int Time;
     
public:
    void SetTime(int valueTime) {
        Time = valueTime;
        }
    int GetTime() {
        return Time;
    }
    void SetSpeedMin(int speedminvalue) {
        speedMin = speedminvalue;
    }
    int GetSpeedMin() {
        return speedMin;
    }
    void SetSpeedMax(int speedmaxvalue) {
        speedMax = speedmaxvalue;
    }
    int GetSpeedMax() {
        return speedMax;
    }
    void SetLongitude() {
      
        longitude = (float)rand() / RAND_MAX * 360;
        if (longitude > 180) {
            longitude -= 180;
            longitude *= -1;
        }
    }
    void SetLatitude() {
        
        latitude = (float)rand() / RAND_MAX * 180;
        if (latitude > 90) {
            latitude -= 90;
            latitude *= -1;
        }
    }
    double  GetLatitude() {
        return latitude;
    }
    double GetLongitude() {
        return longitude;
    }

    string GetName() {
        return name;
    }
    void SetName(string valueName) {
        name = valueName;
    }

    int GetWeight() {
        return weight;
    }
    void SetWeight(int valueWeight) {
        weight = valueWeight;
    }
    int GetHeight() {
        return height;
    }
    void SetHeight(int valueHeight){
        height = valueHeight;
}
    int GetAge() {
        return age;
    }
    void SetAge(int valueAge) {
        age = valueAge;
    }
    void print() {
        cout << "name = " << name << "\n" << "age = " << age << "\n" << "height = " << height << "\n" << "weight = " << weight  << "\n" << "speed min = " <<
            speedMin << "\n" << "speed max = " << speedMax << "\n" << "latitude = " << latitude << "\n" << "longitude = " << longitude<<"\n";
    
    }
    void GetWalking() {
        int sum = 0;
        srand(time(NULL));
        double x = GetLatitude();//начальная широта
        double y = GetLongitude();//гачальная долгота
        print();
        
        long long int R = 6372795;
        double PI = 3.14;
        double x1; //lat
        double y1;//lon
        int Time;
        
        char a;
        a = 26;
        cout << "time: ";
        cin >> Time;
        for (int i = 0; i < Time; i++) {
            int speed = rand() % 80;   
            int nap = rand() % 360;  
            x1 = x + speed * cos(nap * PI / 180) / (R * PI / 180);
            y1 = y + speed * sin(nap * PI / 180) / cos(x * PI / 180) / (R * PI / 180);

            double x_rad = x * PI / 180; 
            double y_rad = y * PI / 180;
            double x1_rad = x1 * PI / 180; 
            double y1_rad = y1 * PI / 180;

            double cos_x = cos(x_rad);
            double cos_x1 = cos(x1_rad);
            double sin_x = sin(x_rad);
            double sin_x1 = sin(x1_rad);
            double delta = y1_rad - y_rad;
            double cos_delta = cos(delta);
            double sin_delta = sin(delta);


            double yE = sqrt(pow(cos_x1 * sin_delta, 2) + pow(cos_x * sin_x1 - sin_x * cos_x1 * cos_delta, 2));
            double xE = sin_x * sin_x1 + cos_x * cos_x1 * cos_delta;
            double ad = atan2(yE, xE);
            double dist = ad * R;
            
            cout << x <<"   " << y <<"        " << x1<<"  " << y1 <<"      " << dist << "\n";
            x = x1;
            y = y1;
            sum += dist;
            
        }
        cout <<"distance traveled: " << sum;
        
    }
    
};
int main()
{
    srand(time(NULL));
    long long int R = 6372795;
    double PI = 3.14;
    Human firstHuman;
    firstHuman.SetAge(10);
    firstHuman.SetHeight(150);
    firstHuman.SetWeight(35);
    firstHuman.SetName("Ben White");
    
    firstHuman.SetSpeedMax(80);
    firstHuman.SetSpeedMin(1);
    firstHuman.SetTime(60);

   
   firstHuman.SetLongitude();
    firstHuman.SetLatitude();
    firstHuman.GetWalking();
    
  
    return 0;
}

