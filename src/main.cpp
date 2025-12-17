#include <iostream>
#include <string>
using namespace std;

int main()
{
    string merchantName, industry, country;
    int monthlyVolume;
    int riskScore = 0;

    cout << "Enter Merchant Name: ";
    getline(cin, merchantName);

    cout << "Enter Industry: ";
    getline(cin, industry);

    cout << "Enter Country: ";
    getline(cin, country);

    cout << "Enter Estimated Monthly Volume (USD): ";
    cin >> monthlyVolume;

    // Industry risk
    if (industry == "forex" || industry == "crypto" || industry == "gambling")
        riskScore += 30;
    else if (industry == "gaming" || industry == "dating")
        riskScore += 25;
    else if (industry == "nutra")
        riskScore += 15;
    else
        riskScore += 5;

    // Country risk
    if (country == "Nigeria" || country == "Brazil" || country == "Russia")
        riskScore += 15;
    else if (country == "India" || country == "Indonesia")
        riskScore += 8;
    else
        riskScore += 2;

    // Volume risk
    if (monthlyVolume > 100000)
        riskScore += 20;
    else if (monthlyVolume >= 20000)
        riskScore += 10;
    else
        riskScore += 5;

    if (riskScore > 100)
        riskScore = 100;

    cout << "\n--- Risk Assessment ---\n";
    cout << "Merchant: " << merchantName << endl;
    cout << "Risk Score: " << riskScore << endl;

    if (riskScore <= 30)
        cout << "Risk Level: LOW (Approved)\n";
    else if (riskScore <= 60)
        cout << "Risk Level: MEDIUM (Enhanced KYC Required)\n";
    else
        cout << "Risk Level: HIGH (Manual Review / Rejected)\n";

    return 0;
}