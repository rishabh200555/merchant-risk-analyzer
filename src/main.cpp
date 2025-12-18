#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string merchantName, industry, country;
    int monthlyVolume;
    int riskScore = 0;

    vector<string> reasons;

    cout << "Enter Merchant Name: ";
    getline(cin, merchantName);

    cout << "Enter Industry: ";
    getline(cin, industry);

    cout << "Enter Country: ";
    getline(cin, country);

    cout << "Enter Estimated Monthly Volume (USD): ";
    cin >> monthlyVolume;

    // -------- Industry Risk --------
    if (industry == "forex" || industry == "crypto" || industry == "gambling")
    {
        riskScore += 30;
        reasons.push_back("High-risk industry (" + industry + ")");
    }
    else if (industry == "gaming" || industry == "dating")
    {
        riskScore += 25;
        reasons.push_back("Medium-high risk industry (" + industry + ")");
    }
    else if (industry == "nutra")
    {
        riskScore += 15;
        reasons.push_back("Elevated-risk industry (nutra)");
    }
    else
    {
        riskScore += 5;
        reasons.push_back("Low-risk industry");
    }

    // -------- Country Risk --------
    if (country == "Nigeria" || country == "Brazil" || country == "Russia")
    {
        riskScore += 15;
        reasons.push_back("High-risk country (" + country + ")");
    }
    else if (country == "India" || country == "Indonesia")
    {
        riskScore += 8;
        reasons.push_back("Medium-risk country (" + country + ")");
    }
    else
    {
        riskScore += 2;
        reasons.push_back("Low-risk country (" + country + ")");
    }

    // -------- Volume Risk --------
    if (monthlyVolume > 100000)
    {
        riskScore += 20;
        reasons.push_back("High transaction volume");
    }
    else if (monthlyVolume >= 20000)
    {
        riskScore += 10;
        reasons.push_back("Medium transaction volume");
    }
    else
    {
        riskScore += 5;
        reasons.push_back("Low transaction volume");
    }

    // Cap risk score
    if (riskScore > 100)
        riskScore = 100;

    // -------- Output --------
    cout << "\n--- Risk Assessment ---\n";
    cout << "Merchant: " << merchantName << endl;
    cout << "Risk Score: " << riskScore << endl;

    if (riskScore <= 30)
        cout << "Risk Level: LOW (Approved)\n";
    else if (riskScore <= 60)
        cout << "Risk Level: MEDIUM (Enhanced KYC Required)\n";
    else
        cout << "Risk Level: HIGH (Manual Review / Rejected)\n";

    cout << "\nReasons:\n";
    for (const string &r : reasons)
    {
        cout << "- " << r << endl;
    }

    return 0;
}