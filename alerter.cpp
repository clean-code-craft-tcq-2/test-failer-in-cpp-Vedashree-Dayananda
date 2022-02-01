#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
#define MAXTHRESHOLDTEMPERATURE 37.2

int networkAlertStubOK(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Network stub to always return true 
	    return 200;
}

int networkAlertStubNOK(float celcius) {
	std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
	// Network stub to always return false
	return 500;
}
int networkAlert(float celcius) {
	//Real network alert
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius >= MAXTHRESHOLDTEMPERATURE))
    {
	    return 200;
    }
    return 500;
}

float farenheitToCelciusConverter(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, int(*networkAlerterFunc)(float)) {
    float celcius = farenheitToCelciusConverter(farenheit);
    int returnCode = networkAlerterFunc(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount++;
    }
}

int main() {
    alertInCelcius(400.5, &networkAlertStubOK);
    assert(alertFailureCount == 1);
    alertInCelcius(303.6, &networkAlertStubOK);
    assert(alertFailureCount == 2);
    alertInCelcius(99.0, &networkAlertStubNOK);
    assert(alertFailureCount == 2);
    alertInCelcius(200.0, &networkAlertStubNOK);
    assert(alertFailureCount == 2);
    alertInCelcius(100.6, &networkAlert);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
