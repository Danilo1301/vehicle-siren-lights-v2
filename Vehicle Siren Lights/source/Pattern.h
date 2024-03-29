#pragma once

#include "pch.h"


struct PatternStep {
	std::vector<int> values;
	int duration;
};

class Pattern {
public:
	std::vector<PatternStep*> steps;
	std::string name;
	std::string fileName;

	Pattern(std::string name) {
		this->name = name;
	}

	PatternStep* AddStep(std::vector<int> values, int duration)
	{
		PatternStep* step = new PatternStep();
		for (size_t i = 0; i < values.size(); i++)
		{
			step->values.push_back(values[i]);
		}
		step->duration = duration;
		steps.push_back(step);
		return step;
	}

	PatternStep* AddStep(bool left, bool middle, bool right, int duration)
	{
		PatternStep* step = new PatternStep();
		step->values.push_back(left ? 1 : 0);
		step->values.push_back(middle ? 1 : 0);
		step->values.push_back(right ? 1 : 0);
		step->duration = duration;
		steps.push_back(step);
		return step;
	}

	/*
	void RemoveStep(PatternStep* step)
	{
		steps.erase(std::find(steps.begin(), steps.end(), step));
		delete step;
	}
	*/

	int GetMaxTime()
	{
		int time = 0;
		for (PatternStep* step : steps) time += step->duration;
		return time;
	}

	/*
	Json::Value ToJSON() {
		Json::Value value = Json::objectValue;
		value["name"] = name;

		value["steps"] = Json::arrayValue;
		for (auto step : steps) {
			Json::Value stepValue;
			stepValue["duration"] = step->duration;

			stepValue["values"] = Json::arrayValue;
			for (auto val : step->values)
			{
				stepValue["values"].append(val);
			}

			value["steps"].append(stepValue);
		}

		return value;
	}
	*/

	void FromJSON(Json::Value value) {
		name = value["name"].asString();

		for (int step_i = 0; step_i < (int)value["steps"].size(); step_i++)
		{
			Json::Value step = value["steps"][step_i];

			int duration = step["duration"].asInt();

			std::vector<int> values;
			for (int val_i = 0; val_i < (int)step["values"].size(); val_i++)
			{
				values.push_back(step["values"][val_i].asInt());
			}

			AddStep(values, duration);
		}
	}
};

struct PatternCycleStep {
	Pattern* pattern;
	int duration;
	bool lerpColor;
};