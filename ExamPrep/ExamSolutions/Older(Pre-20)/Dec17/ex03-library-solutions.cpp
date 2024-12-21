#include <iostream>
#include "ex03-library.h"

//Do not modify
CurrencyConverter::CurrencyConverter() {
	currencies.insert("DKK");
	currencyToExchangeRate["DKK"]=1;
}

//Do not modify
bool CurrencyConverter::supportsCurrency(string currencyCode){
	//if(currencies.count(currencyCode) > 0){
	if(currencies.find(currencyCode) != currencies.end()){
		//I have the currency.
		return true;
	}
	else{
		return false;
	}
}

//Exercise 3 (a) Check and correct if necessary
void CurrencyConverter::print(){
	cout << "The converter supports the following currencies:"<<endl;
	for (map<string,double>::iterator it=currencyToExchangeRate.begin(); it!=currencyToExchangeRate.end(); ++it){
		cout << ' '<< "currency " << it->first  << " has exchange rate " << it->second << endl;
	}
}
/*
void CurrencyConverter::printWrong(){
	cout << "The converter supports the following currencies:"<<endl;
	for (map<string,double>::iterator it=currencyToExchangeRate.begin(); it!=currencyToExchangeRate.end(); ++it){
	  //cout << ' '<< "currency " << it->first  << " has exchange rate " << it->second << endl;
		cout << ' '<< "currency " << it->second << " has exchange rate " << it->first  << endl;
	}
}
*/

//Exercise 3 (b) Check and correct if necessary
bool CurrencyConverter::addCurrency(string currencyCode,double exchangeRateToDKK) {
	if(supportsCurrency(currencyCode)){
		//I already have this element. Hence I return false
		return false;
	}
	else if(exchangeRateToDKK <= 0){
		//Exchange rates must be positive
		return false;
	}
	else{
		currencies.insert(currencyCode);
		currencyToExchangeRate[currencyCode]=exchangeRateToDKK;
		return true;
	}
}
/*
bool CurrencyConverter::addCurrencyWrong(string currencyCode,double exchangeRateToDKK) {
    if(supportsCurrency(currencyCode)){
		//I already have this element. Hence I return false
		return false;
	}
	else if(exchangeRateToDKK <= 0){
		//Exchange rates must be positive
		return false;
	}
	else{
		currencies.insert(currencyCode);
	  //currencyToExchangeRate[currencyCode]=exchangeRateToDKK;
	    currencyToExchangeRate[exchangeRateToDKK]=currencyCode;
		return true;
	}
}
*/

//Exercise 3 (c) Implement this function
bool CurrencyConverter::updateExchangeRate(string currencyCode,double newExchangeRate) {
	if(!supportsCurrency(currencyCode)){
		//I do not have yet the currency. Hence I cannot update it. It should first be added
		return false;
	}
	else if(newExchangeRate <= 0){
		//Exchange rates must be positive
		return false;
	}
	else if(currencyCode=="DKK"){
		//It is not possible to update the exchange rate of DKK.
		return false;
	}
	else{
		currencyToExchangeRate[currencyCode]=newExchangeRate;
		return true;
	}
}

//Exercise 3 (d) Implement this function
double CurrencyConverter::convertToDKK(double amount, string currencyCodeOfSource) {
	if(!supportsCurrency(currencyCodeOfSource)){
		//I do not have an exchange rate for the currency. Hence I cannot handle the request.
		return -1;
	}
	else if(amount <= 0){
		//Amounts must be positive
		return -1;
	}
	else{
		double exchangeRateFromSourceToDKK=currencyToExchangeRate[currencyCodeOfSource];
		double amountDKK = amount*exchangeRateFromSourceToDKK;
		return amountDKK;
	}
}

//Exercise 3 (d) Implement this function
double CurrencyConverter::convertFromDKK(double amountDKK,string currencyCodeOfTarget) {
	if(!supportsCurrency(currencyCodeOfTarget)){
		//I do not have an exchange rate for the currency. Hence I cannot handle the request.
		return -1;
	}
	else if(amountDKK <= 0){
		//Amounts must be positive
		return -1;
	}
	else{
		double exchangeRateFromTargetToDKK=currencyToExchangeRate[currencyCodeOfTarget];
		double amountCurrency = amountDKK/exchangeRateFromTargetToDKK;
		return amountCurrency;
	}
}
