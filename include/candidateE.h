#ifndef CANDIDATEE_H
#define CANDIDATEE_H

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

namespace AMWPHI001
{
typedef std::vector<std::string>
	strVec;

class Hypothesis
{
private:
	strVec attributes;

	/* 0 = negative || 1 = positve || 2 = generalHypo || 3 = specificHypo */
	int status;

public:
	Hypothesis(strVec stringVector, int hypoStatus) : attributes(stringVector), status(hypoStatus) {}
	~Hypothesis() = default;

	Hypothesis compareHypotheses(std::vector<Hypothesis> exampleTable);

	strVec getAttibutes()
	{
		return this->attributes;
	}

	std::string getAttibute(int i)
	{
		return this->attributes[i];
	}

	int getStatus()
	{
		return this->status;
	}

	int size()
	{
		return this->attributes.size();
	}

	void setAttribute(std::string attrib, int index)
	{
		this->attributes[index] = attrib;
	}

	void setStatus(int status)
	{
		this->status = status;
	}

	void printHypothesis()
	{
		printf("< %s, %s, %s, %s, %s, %s >\n", this->getAttibute(0).c_str(), this->getAttibute(1).c_str(), this->getAttibute(2).c_str(), this->getAttibute(3).c_str(), this->getAttibute(4).c_str(), this->getAttibute(5).c_str());
	}

	//TODO: overload [] operator for this class to return attributes at specified index
};

class candidateE
{

private:
public:
	candidateE() = default;
	~candidateE() = default;

	std::vector<Hypothesis> runcandidateE(Hypothesis generalHypo, Hypothesis specificHypo, std::vector<Hypothesis> exampleTable);
};
} // namespace AMWPHI001

#endif // !CANDIDATEE_H
