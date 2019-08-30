#include "../include/hypothesis.h"
#include "../include/candidateE.h"

using namespace AMWPHI001;

Hypothesis Hypothesis::compareHypotheses(std::vector<Hypothesis> exampleTable)
{
	if (this->getStatus() == 2) // General case
	{
		/* code */
	}
	else if (this->getStatus() == 3) // Specific case
	{
		/* code */
	}
	else
	{
		std::cout << "Error comparing hypothesis!" << std::endl;
	}
}

std::vector<Hypothesis> candidateE::runcandidateE(Hypothesis generalHypo, Hypothesis specificHypo, std::vector<Hypothesis> exampleTable)
{
	std::vector<Hypothesis> answerSet{};

	Hypothesis computedGeneralHypo = generalHypo.compareHypotheses(exampleTable);
	Hypothesis computedSpecificHypo = specificHypo.compareHypotheses(exampleTable);

	answerSet.push_back(computedGeneralHypo);
	answerSet.push_back(computedSpecificHypo);

	return answerSet;
}
