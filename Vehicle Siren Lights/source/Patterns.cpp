#include "Patterns.h"

std::vector<Pattern*> Patterns::m_Patterns;

Pattern* Patterns::CreatePattern(std::string name) {
	Pattern* pattern = new Pattern(name);
	m_Patterns.push_back(pattern);

	Log::file << "[Patterns] CreatePattern " << name << " (" << std::to_string(m_Patterns.size()) << " total)" << std::endl;
	return pattern;
}

void Patterns::RemovePattern(Pattern* pattern) {
	m_Patterns.erase(std::find(m_Patterns.begin(), m_Patterns.end(), pattern));

	Log::file << "RemovePattern " << pattern->name << " - total " << std::to_string(m_Patterns.size()) << std::endl;

	delete pattern;
}