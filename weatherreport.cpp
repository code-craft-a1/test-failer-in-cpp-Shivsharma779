#include <string>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 70;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 52;
        }
    };
    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (precipitation >= 60)
                report = "rainy";
            else if (precipitation < 20)
                report = "Sunny";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestRainy()
    {
        SensorStub sensor;
        string report = Report(sensor);
        cout << report << endl;
        EXPECT_TRUE(report.find("rain") != string::npos);
    }

    void TestHighPrecipitation()
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        SensorStub sensor;

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        string report = Report(sensor);
        EXPECT_GT(report.length(), 0);
    }

    class SensorHighPrecipLowWindStub : public IWeatherSensor {
        int Humidity() const override { return 80; }
        int Precipitation() const override { return 75; }    // high precipitation > 60
        double TemperatureInC() const override { return 26; }
        int WindSpeedKMPH() const override { return 45; }    // low wind speed <= 50
    };

    void TestHighPrecipLowWind()
    {
        SensorHighPrecipLowWindStub sensor;
        string report = Report(sensor);
        cout << "Report for high precip, low wind: " << report << endl;
        EXPECT_NE(report.find("rain") , string::npos) << "Expected 'rain' in report, got: " << report;
    }
}

void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}

void testRainyReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestHighPrecipLowWind();
}

