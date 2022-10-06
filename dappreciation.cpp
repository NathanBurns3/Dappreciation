#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

/*
   * the purpose of the main method is to calculate
   * the resale price of a used car based off of 4
   * different components (car year, previous accidents,
   * if it has premium features, and the original msrp).
*/
int main() {
  //variable to store the current year
  const int currentYear = 2022;

  //variables that are retrieving values from the given methods
  int carYear = currentYear - car_model_year();
  int accidents = car_accidents();
  /*
   * calling the "car_has_premium_options" method and storing it
   * in the "premiumOptions" variable the purpose of the method
   * is to ask the user if the car has any premium features and
   * answer with "yes" or "no". If the user says "yes" then the
   * method will return "true", if they say "no" then it will
   * return "false"
  */
  bool premiumOptions = car_has_premium_options();
  double msrp = car_msrp();
  
  //variables that will be used to store the differnt percentages and resale price
  double baselineResalePercentage = 0.0;
  double wreckPenaltyPercentage = 0.0;
  double premiumPercentage = 0.0;
  double finalResalePercentage = 0.0;
  double resalePrice = 0.0;

  //calculates the baseline percentage based off of the different car year tiers
  if (carYear <= 4) {
    baselineResalePercentage = .85;
  }
  else if (carYear <= 8) {
    baselineResalePercentage = .63;
  }
  else {
    baselineResalePercentage = .45;
  }

  //calculates the wreck percentage based off of the differnet accident tiers
  if (accidents == 0) {
    wreckPenaltyPercentage = 0.0;
  }
  else if (accidents == 1) {
    wreckPenaltyPercentage = .02; 
  }
  else if (accidents == 2) {
    wreckPenaltyPercentage = .1;
  }
  else {
    wreckPenaltyPercentage = .2;
  }

  //calculates the premium percentage based off of the premium options
  if (premiumOptions) {
    premiumPercentage = .05;
  }
  else {
    premiumPercentage = 0.0;
  }

  //calculates the final resale percentage and the resale price
  finalResalePercentage = baselineResalePercentage - wreckPenaltyPercentage + premiumPercentage;
  resalePrice = msrp * finalResalePercentage;

  //determines if the car is eligible or not
  const int eligibleYear = 10;
  const int eligibleAccidents = 3;

  if (carYear <= eligibleYear && accidents <= eligibleAccidents) {
    print_eligible_message(resalePrice);
  }
  else {
    print_ineligible_message();
  }

  return 0;
}