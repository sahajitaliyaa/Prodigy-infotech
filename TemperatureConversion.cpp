#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

int main() {
    double temperature;
    char unit;

    cout << "Enter temperature value: ";
    cin >> temperature;

    cout << "Enter the unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
        double fahrenheit = celsiusToFahrenheit(temperature);
        double kelvin = celsiusToKelvin(temperature);
        cout << "Temperature in Fahrenheit: " << fahrenheit << " F" << endl;
        cout << "Temperature in Kelvin: " << kelvin << " K" << endl;
    } else if (unit == 'F' || unit == 'f') {
        double celsius = fahrenheitToCelsius(temperature);
        double kelvin = fahrenheitToKelvin(temperature);
        cout << "Temperature in Celsius: " << celsius << " C" << endl;
        cout << "Temperature in Kelvin: " << kelvin << " K" << endl;
    } else if (unit == 'K' || unit == 'k') {
        double celsius = kelvinToCelsius(temperature);
        double fahrenheit = kelvinToFahrenheit(temperature);
        cout << "Temperature in Celsius: " << celsius << " C" << endl;
        cout << "Temperature in Fahrenheit: " << fahrenheit << " F" << endl;
    } else {
        cout << "Invalid unit of measurement entered." << endl;
    }

    return 0;
}
