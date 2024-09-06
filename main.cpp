#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

/*!
 @brief Lambda is an expression for creating a list of unique numbers.
 @param values a list of numbers. The numbers can be repeated.
*/
auto unique_values = [](std::vector<int> values)
{
    std::unordered_set<int> auxiliary_vector;
    std::vector<int> unique_numbers;

    // checking for emptiness
	if(values.empty())
		return std::make_unique<std::vector<int>>();

    // clearing lists
    auxiliary_vector.clear();
    unique_numbers.clear();
    // iterating through all the elements
	for(const auto & value: values)
	{
        // if there is no element in the auxiliary array
		if(auxiliary_vector.count(value) == 0) {
            // then add it to the auxiliary and array of unique elements
            auxiliary_vector.insert(value);
        	unique_numbers.push_back(value);
        }
	}

    // return a list of unique items
    return std::make_unique<std::vector<int>>(unique_numbers);
};

/*!
 @brief A subroutine for printing list items with a title.
 @param inList the original list.
 @param inTitle the title of the list.
*/
void print(const std::vector<int> & inList, const std::string & inTitle)
{
    std::cout << inTitle << ": [";
    for (const auto & elem : inList)
        std::cout << elem << ' ';
    
    std::cout << "]\n";
}

int main()
{
    // the original list of items
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 5, 2};

    // calling the lambda function
	auto result = unique_values(values);
    
    // output of the result
    print(values, "Source");
    print(*result, "Result");

    // program shutdown
    return 0;
}
