#include <iostream>
#include <assert.h>

#define MINTHRESHOLDTEMPERATURE 36.1
#define MAXTHRESHOLDTEMPERATURE 37.2

int alertFailureCount = 0;
int networkAlertCount = 0;


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    if ((celcius <= MINTHRESHOLDTEMPERATURE) && (celcius >= MAXTHRESHOLDTEMPERATURE))
    {
	    return 200;
    }
    networkAlertCount++;
    return 500;
}

int networkAlert(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if ((celcius <= MINTHRESHOLDTEMPERATURE) && (celcius >= MAXTHRESHOLDTEMPERATURE))
    {
	    return 200;
    }
    networkAlertCount++;
    return 500;
}

float farenheitToCelciusConverter(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, int(*networkAlerter)(float)) {
    float celcius = farenheitToCelciusConverter(farenheit);
    int returnCode = networkAlerter(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5, &networkAlertStub);
    assert(alertFailureCount == networkAlertCount);
    alertInCelcius(303.6, &networkAlertStub);
    assert(alertFailureCount == networkAlertCount);
    alertInCelcius(100.6, &networkAlert);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << networkAlertCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
