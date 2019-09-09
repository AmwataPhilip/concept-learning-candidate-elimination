#include "../include/candidateE.h"
#include "../include/candidateE.h"

using namespace AMWPHI001;

Hypothesis Hypothesis::compareHypotheses(std::vector<Hypothesis> exampleTable)
{
	if (this->getStatus() == 2) // General case
	{
		for (auto hypothesis : exampleTable)
		{
			if (hypothesis.getStatus() == 0)
			{
				for (int i = 0; i < this->size(); i++)
				{
					if ((this->getAttibute(i) == hypothesis.getAttibute(i)) | this->getAttibute(i) == "?")
					{
						continue;
					}
					else
					{
						this->setAttribute(hypothesis.getAttibute(i), i);
					}
				}
			}
		}
		return this;
	}
	else if (this->getStatus() == 3) // Specific case
	{
		for (auto hypothesis : exampleTable)
		{
			if (hypothesis.getStatus() == 1)
			{
				for (int i = 0; i < this->size(); i++)
				{
					if ((this->getAttibute(i) == hypothesis.getAttibute(i)) | this->getAttibute(i) == "?")
					{
						continue;
					}
					else
					{
						this->setAttribute("?", i);
					}
				}
			}
		}
		return this;
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
