#pragma once
#include "../Ch4Common.h"

void test4_7();

class projectGraph;
class project;
class projectDependency;

enum state
{
	notProcess,
	processing,
	processed
};

class projectDependency
{
public:
	projectDependency(string pHead, string pLinked)
	{
		this->projectHead = pHead;
		this->projectLinked = pLinked;
	}

	string getHeadProjectName()
	{
		return projectHead;
	}

	string getLinkedProjectName()
	{
		return projectLinked;
	}

private:
	string projectHead;
	string projectLinked;
};

class project
{
public:
	project(string pName)
	{
		this->projectName = pName;
		this->linkedProject = vector<project*>();
		this->dependencyCount = 0;
		this->curState = notProcess;
	}

	void addChild(project* cNode)
	{
		linkedProject.push_back(cNode);
		cNode->addDependency();
	}

	vector<project*> getChildren()
	{
		return linkedProject;
	}

	string getName()
	{
		return projectName;
	}

	void addDependency()
	{
		dependencyCount++;
	}

	void subDependency()
	{
		dependencyCount--;
	}

	int getDependencyNum()
	{
		return dependencyCount;
	}

	state getState()
	{
		return curState;
	}

	void setState(state s)
	{
		curState = s;
	}

private:
	string projectName;
	vector<project*> linkedProject;
	int dependencyCount;
	state curState;
};

class projectGraph
{
public:
	projectGraph(vector<projectDependency> dependencyLists)
	{
		for(auto dependencyList : dependencyLists)
		{
			string headProjectName = dependencyList.getHeadProjectName();
			string linkedProjectName = dependencyList.getLinkedProjectName();
			project* curProject = NULL;

			if (projectMapping.find(headProjectName) != projectMapping.end())
			{
				curProject = projectMapping[headProjectName];
			}
			else
			{
				curProject = createProject(headProjectName);
			}

			if (linkedProjectName != "")
			{
				this->addLinkedProject(curProject, linkedProjectName);
			}
		}
	}

	void printProjectDependency()
	{
		for (auto curP : this->projects)
		{
			cout << "project: " << curP->getName() << "--> ";
			vector<project*> linkedProject = curP->getChildren();

			for (auto curLP : linkedProject)
			{
				cout << curLP->getName() << " ";
			}

			cout << endl;
		}

		cout << endl;
	}

	stack<string> buildProjectOrderRecursive()
	{
		stack<string> projectOrder;

		for (auto curProj : this->projects)
		{
			if (curProj->getState() == notProcess)
			{
				bool loopDetected = depthFirstSearch(curProj, projectOrder);

				if (loopDetected == true)
				{
					return stack<string>();
				}
			}
		}

		return projectOrder;
	}

	vector<string> buildProjectOrder()
	{
		vector<string> projectOrder;

		int processedNum = 0;

		for (auto curP : this->projects)
		{
			if (curP->getDependencyNum() == 0)
			{
				projectOrder.push_back(curP->getName());
			}
		}

		while (processedNum != projectOrder.size())
		{
			string toBeProcessedName = projectOrder[processedNum];
			project* toBeProcessedProj = projectMapping[toBeProcessedName];

			removeDependency(toBeProcessedProj, projectOrder);

			processedNum++;
		}

		if (projectOrder.size() != this->projects.size())
		{
			projectOrder.clear();
		}

		return projectOrder;
	}

private:
	bool depthFirstSearch(project* curProject, stack<string>& projectOrder)
	{
		curProject->setState(processing);

		vector<project*> children = curProject->getChildren();

		for (auto childProj : children)
		{
			if (childProj->getState() == processing)
			{
				return true;
			}

			if (childProj->getState() == notProcess)
			{
				bool cycleDetected = depthFirstSearch(childProj, projectOrder);
				
				if (cycleDetected == true)
				{
					return true;
				}
			}
		}

		projectOrder.push(curProject->getName());
		curProject->setState(processed);

		return false;
	}

	void removeDependency(project* curProject, vector<string>& projectOrder)
	{
		vector<project*> depProjs = curProject->getChildren();

		for (auto depP : depProjs)
		{
			depP->subDependency();

			if (depP->getDependencyNum() == 0)
			{
				projectOrder.push_back(depP->getName());
			}
		}

		depProjs.clear();
	}

	void addLinkedProject(project* curProject, string linkedProject)
	{
		if (projectMapping.find(linkedProject) != projectMapping.end())
		{
			curProject->addChild(projectMapping[linkedProject]);
		}
		else
		{
			project* newProject = createProject(linkedProject);

			curProject->addChild(newProject);
		}
	}

	project* createProject(string projectName)
	{
		project* newProject = new project(projectName);

		projects.push_back(newProject);
		projectMapping.insert(pair<string, project*>(projectName, newProject));

		return newProject;
	}

	vector<project*> projects;
	map<string, project*> projectMapping;
};
