#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string merchantName, industry, country;
    string websiteText;
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
    cin.ignore();

    cout << "Enter Website Keywords / Description: ";
    getline(cin, websiteText);

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

    // -------- Website Keyword Risk --------
    vector<string> riskyKeywords = {
        "forex", "trading", "leverage", "guaranteed",
        "casino", "bet", "profit", "investment"};

    for (const string &word : riskyKeywords)
    {
        if (websiteText.find(word) != string::npos)
        {
            riskScore += 5;
            reasons.push_back("Risky website keyword detected (" + word + ")");
        }
    }

    // Cap risk score
    if (riskScore > 100)
        riskScore = 100;

    // -------- Decision Logic --------
    string riskLevel, decision, action;

    if (riskScore <= 30)
    {
        riskLevel = "LOW";
        decision = "Approved";
        action = "Standard onboarding";
    }
    else if (riskScore <= 60)
    {
        riskLevel = "MEDIUM";
        decision = "Review Required";
        action = "Enhanced KYC + Compliance checks";
    }
    else
    {
        riskLevel = "HIGH";
        decision = "Rejected / Manual Review";
        action = "Senior risk team approval required";
    }

    // -------- Final Report --------
    cout << "\n=================================\n";
    cout << "      MERCHANT RISK REPORT\n";
    cout << "=================================\n";
    cout << "Merchant Name   : " << merchantName << endl;
    cout << "Risk Score      : " << riskScore << endl;
    cout << "Risk Level      : " << riskLevel << endl;
    cout << "Decision        : " << decision << endl;
    cout << "Required Action : " << action << endl;

    cout << "\nRisk Signals Identified:\n";
    for (const string &r : reasons)
    {
        cout << " - " << r << endl;
    }

    cout << "=================================\n";

    return 0;
}