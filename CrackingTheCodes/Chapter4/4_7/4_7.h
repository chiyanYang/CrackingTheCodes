#pragma once
#include "../Ch4Common.h"

void test4_7();

class projectGraph;
class project;
class projectDependency;


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
		linkedProject = vector<project*>();
		dependencyCount = 0;
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

private:
	string projectName;
	vector<project*> linkedProject;
	int dependencyCount;
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
