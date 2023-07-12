/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*Weather app/
Name D.Sandhya 
college vivekanandha college of engineering for women autonomous 

Data used Location
Methods used 
class and objects , if else,functions*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WeatherData {
private:
    string date;
    string location;
    string weatherCondition;
    double temperature;
    double rainPossibility;
    double humidity;

public:
    WeatherData(const string& dt, const string& loc, const string& condition, double temp, double rain, double hum) {
        date = dt;
        location = loc;
        weatherCondition = condition;
        temperature = temp;
        rainPossibility = rain;
        humidity = hum;
    }

    void displayWeather() const {
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Weather Condition: " << weatherCondition << endl;
        cout << "Temperature: " << temperature << " degrees Celsius" << endl;
        cout << "Rain Possibility: " << rainPossibility << "%" << endl;
        cout << "Humidity: " << humidity << "%" << endl;
        cout << endl;
    }
};

class WeatherApp {
private:
    vector<WeatherData> weatherData;

public:
    void addWeatherData(const WeatherData& data) {
        weatherData.push_back(data);
    }

    void displayTodayWeather() const {
        if (!weatherData.empty()) {
            cout << "Today's Weather:" << endl;
            weatherData[0].displayWeather();
        } else {
            cout << "No weather data available." << endl;
        }
    }

    void displayYesterdayWeather() const {
        if (weatherData.size() >= 2) {
            cout << "Yesterday's Weather:" << endl;
            weatherData[1].displayWeather();
        } else {
            cout << "No weather data available." << endl;
        }
    }

    void displayTomorrowWeather() const {
        if (weatherData.size() >= 3) {
            cout << "Tomorrow's Weather:" << endl;
            weatherData[2].displayWeather();
        } else {
            cout << "No weather data available." << endl;
        }
    }

    void displayWeeklyReport() const {
        if (weatherData.size() >= 7) {
            cout << "Weekly Weather Report:" << endl;
            for (int i = 0; i < 7; i++) {
                cout << "Day " << i + 1 << ":" << endl;
                weatherData[i].displayWeather();
            }
        } else {
            cout << "No weather data available." << endl;
        }
    }

    void displayMonthlyWeather() const {
        if (!weatherData.empty()) {
            cout << "Monthly Weather Overview:" << endl;
            for (const WeatherData& data : weatherData) {
                data.displayWeather();
            }
        } else {
            cout << "No weather data available." << endl;
        }
    }
};

int main() {
    WeatherApp weatherApp;

    weatherApp.addWeatherData(WeatherData("2023-07-09 ", "Thiruchengode", "Cloudy", 25.5, 30.0, 75.0));
    weatherApp.addWeatherData(WeatherData("2023-07-10 ", "Trichy", "Rain", 23.8, 60.0, 80.0));
    weatherApp.addWeatherData(WeatherData("2023-07-11", "Mumbai", "Dry", 28.0, 10.0, 65.0));

    
    weatherApp.displayTodayWeather();
    weatherApp.displayYesterdayWeather();
    weatherApp.displayTomorrowWeather();

    weatherApp.displayWeeklyReport();

    weatherApp.displayMonthlyWeather();

    return 0;
}