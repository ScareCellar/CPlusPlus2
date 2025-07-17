#include "AudioSystem.h"


namespace blood {

	bool AudioSystem::CheckFMODResult(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}
	}


	bool AudioSystem::Initialize() {
		FMOD_RESULT result = FMOD::System_Create(&m_system);

		if (!CheckFMODResult(result)) return false;

		void* extradriverdata = nullptr;
		result = m_system->init(32, FMOD_INIT_NORMAL, extradriverdata);

		if (!CheckFMODResult(result)) return false;

		return true;
	}
	void AudioSystem::Shutdown() {
		CheckFMODResult(m_system->release());


	}

	void AudioSystem::Update() {
		CheckFMODResult(m_system->update());
	}


	bool AudioSystem::AddSound(const std::string& filename, const std::string& name) {
		std::string key = (name.empty()) ? filename : name;
		key = toLower(key);

		//check if key exists in sounds map
		if (m_sounds.find(key) != m_sounds.end()) {
			std::cerr << "AudioSystem : Name already exists" << key << std::endl;
			return false;
		}

		//create sound from key
		FMOD::Sound* sound = nullptr;

		FMOD_RESULT result = m_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);

		if (!CheckFMODResult(result)) return false;

		//insert sound into map
		m_sounds[key] = sound;

		return false;
	}

	bool AudioSystem::PlaySound(const std::string& name) {
		std::string key = name;
		for (char c : key) {
			c = std::tolower(c);
		}


		if (m_sounds.find(name) == m_sounds.end()) {
			std::cerr << "AudioSystem : name doesn't exist" << key << std::endl;
			return false;
		}

		FMOD_RESULT result = m_system->playSound(m_sounds[name], 0, false, nullptr);
		if (!CheckFMODResult(result)) return false;

		return true;
	}
}