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
	}

	void addChild(project* cNode)
	{
		linkedProject.push_back(cNode);
	}

	vector<project*> getChildren()
	{
		return linkedProject;
	}

	string getName()
	{
		return projectName;
	}

private:
	string projectName;
	vector<project*> linkedProject;
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

			this->addLinkedProject(curProject, linkedProjectName);
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

		int idxToBeProcessed = 0;

		for (auto curP : this->projects)
		{

		}

	}

private:
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
