#include <iostream>
#include <string>
#include <map>
#include <vector>

class HealthWellness {
	public:	
		//default constructor
		HealthWellness();
	
		//setters
		void setGoalWeight(float w);
		void setCurrentWeight(float w);
		void setActivityLevel(std::string l);
		void setNumberOfMeals(int n);

		//getters
		float getGoalWeight() const;
		float getCurrentWeight() const;
		std::string getActivityLevel() const;
		int getNumberOfMeals() const;

		//other methods
		float calculateBodyMassIndex() const;
		std::vector<std::string> optimalMealPlan() const;
	
	private:
		float goalWeight;
		float currentWeight;
		std::string activityLevel;
		int numberOfMeals;
		std::map<std::string, std::vector<std::string>> mealPlans;
};

//constructor
HealthWellness::HealthWellness() : goalWeight(0.0f), currentWeight(0.0f), activityLevel(""), numberOfMeals(0) {
	//initialize mealPlans
	std::vector<std::string> breakfast = {"Oatmeal", "Yogurt", "Fruit Smoothie"};
	mealPlans["Breakfast"] = breakfast;

	std::vector<std::string> lunch = {"Salad", "Sandwich", "Vegetable Stir-Fry"};
	mealPlans["Lunch"] = lunch;

	std::vector<std::string> dinner = {"Grilled Chicken", "Fish", "Vegetable Soup"};
	mealPlans["Dinner"] = dinner;

	std::vector<std::string> snacks = {"Fruit", "Nuts", "Vegetable Sticks"};
	mealPlans["Snacks"] = snacks;
}

//setters
void HealthWellness::setGoalWeight(float w) {
	goalWeight = w;
}

void HealthWellness::setCurrentWeight(float w) {
	currentWeight = w;
}

void HealthWellness::setActivityLevel(std::string l) {
	activityLevel = l;
}

void HealthWellness::setNumberOfMeals(int n) {
	numberOfMeals = n;
}

//getters
float HealthWellness::getGoalWeight() const {
	return goalWeight;
}

float HealthWellness::getCurrentWeight() const {
	return currentWeight;
}

std::string HealthWellness::getActivityLevel() const {
	return activityLevel;
}

int HealthWellness::getNumberOfMeals() const {
	return numberOfMeals;
}

//other methods
float HealthWellness::calculateBodyMassIndex() const {
	float bmi = 0.0f;
	
	if (currentWeight > 0 && goalWeight > 0) {
		bmi = (currentWeight - goalWeight) / (goalWeight * 0.01f);
	}

	return bmi;
}

std::vector<std::string> HealthWellness::optimalMealPlan() const {
	std::vector<std::string> plan;

	int mealsPerDay = numberOfMeals / 7;

	if (activityLevel == "Light") {
		//light activity
		for (int i = 0; i < mealsPerDay; i++) {
			plan.push_back(mealPlans["Breakfast"][1]);
			plan.push_back(mealPlans["Lunch"][1]);
			plan.push_back(mealPlans["Dinner"][1]);
			plan.push_back(mealPlans["Snacks"][0]);
		}
	}
	else if (activityLevel == "Moderate") {
		//moderate activity
		for (int i = 0; i < mealsPerDay; i++) {
			plan.push_back(mealPlans["Breakfast"][0]);
			plan.push_back(mealPlans["Lunch"][2]);
			plan.push_back(mealPlans["Dinner"][2]);
			plan.push_back(mealPlans["Snacks"][1]);
		}
	}
	else if (activityLevel == "Heavy") {
		//heavy activity
		for (int i = 0; i < mealsPerDay; i++) {
			plan.push_back(mealPlans["Breakfast"][2]);
			plan.push_back(mealPlans["Lunch"][0]);
			plan.push_back(mealPlans["Dinner"][0]);
			plan.push_back(mealPlans["Snacks"][2]);
		}
	}

	return plan;
}

int main() {
	//create HealthWellness object
	HealthWellness hw;
	
	//set inputs
	hw.setGoalWeight(80.0f);
	hw.setCurrentWeight(85.0f);
	hw.setActivityLevel("Heavy");
	hw.setNumberOfMeals(21);

	//print inputs
	std::cout << "Goal weight: " << hw.getGoalWeight() << std::endl;
	std::cout << "Current weight: " << hw.getCurrentWeight() << std::endl;
	std::cout << "Activity level: " << hw.getActivityLevel() << std::endl;
	std::cout << "Number of meals: " << hw.getNumberOfMeals() << std::endl;

	//print BMI
	std::cout << "Body mass index: " << hw.calculateBodyMassIndex() << std::endl;

	//print optimal meal plan
	std::cout << "Optimal meal plan:" << std::endl;
	std::vector<std::string> plan = hw.optimalMealPlan();

	for (int i = 0; i < plan.size(); i++) {
		std::cout << plan[i] << std::endl;
	}

	return 0;
}