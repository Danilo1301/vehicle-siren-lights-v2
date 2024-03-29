#include "Patterns.h"

#include "log/Log.h"

std::vector<Pattern*> Patterns::m_Patterns;

Pattern* Patterns::CreatePattern(std::string name) {
	Pattern* pattern = new Pattern(name);
	m_Patterns.push_back(pattern);

	Log::file << "[Patterns] CreatePattern " << name << " (" << std::to_string(m_Patterns.size()) << " total)" << std::endl;
	return pattern;
}

Pattern* Patterns::GetPatternByFileName(std::string fileName) {
	
	for (auto pattern : m_Patterns)
	{
		if (fileName.compare(pattern->fileName) == 0) return pattern;
	}

	return NULL;
}


void Patterns::RemovePattern(Pattern* pattern) {
	m_Patterns.erase(std::find(m_Patterns.begin(), m_Patterns.end(), pattern));

	Log::file << "[Patterns] RemovePattern '" << pattern->name << "' (" << std::to_string(m_Patterns.size()) + " total)" << std::endl;

	delete pattern;
}

void Patterns::RemoveAllPatterns() {
	Log::file << "[Patterns] RemoveAllPatterns" << std::endl;

	while (m_Patterns.size() > 0) {
		RemovePattern(m_Patterns[0]);
	}
}