# Merchant Risk Analyzer (C++)

A rule-based underwriting and merchant pre-screening tool inspired by real-world
Payment Service Provider (PSP) onboarding workflows for high-risk merchants.

This project simulates how PSPs evaluate merchants before approval by assessing
business risk, geographic risk, transaction volume, and website compliance signals.

---

## Problem Statement
High-risk merchants (Forex, Gaming, Crypto, Gambling, etc.) require detailed
risk evaluation before onboarding. PSPs use structured risk rules to decide
whether a merchant should be approved, reviewed, or rejected.

This project models that decision logic in a simplified, explainable way.

---

## Key Features
- Rule-based risk scoring (0–100)
- Industry, country, and transaction volume risk evaluation
- Website keyword-based compliance risk detection
- Explainable decisions with detailed risk reasons
- Professional underwriting-style decision output

---

## Inputs
- Merchant name
- Industry
- Country
- Estimated monthly transaction volume
- Website keywords / description

---

## Output
- Risk Score
- Risk Level (Low / Medium / High)
- Decision (Approve / Review / Reject)
- Required Action
- Clear list of risk signals detected

---

## Sample Run

**Input**
- Industry: Forex  
- Country: Brazil  
- Monthly Volume: 150000  
- Website Keywords: forex trading guaranteed profits leverage  

**Output**
- Risk Score: High
- Decision: Rejected / Manual Review
- Reasons:
  - High-risk industry (Forex)
  - High-risk country (Brazil)
  - High transaction volume
  - Risky website keywords detected

---

## Tech Stack
- Language: C++
- Concepts: Rule-based systems, decision logic, explainability
- Tools: Git, GitHub, Command-line execution

---

## Learning Outcome
This project helped me understand how real-world business rules in payments and
compliance are translated into software logic and explainable system decisions.