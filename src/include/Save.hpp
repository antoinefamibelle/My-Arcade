/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Save
*/

#pragma once

#include <string>
#include <list>
#include <vector>
#include <Logs.hpp>
#include "IDisplayModule.hpp"

class Save : public log::Logs
{
    public:
        Save();
        ~Save();

        void addParam(const std::string &section, const std::string &newParam); // Adding a param in the list _params, if existing in the section, it's just update
        void updateParam(const std::string &section, const std::string &newParam); // Update a param in the list _params, if inexisting in the section, it's add
        void saveParams(); // Save All list elements depends on their pair.first (it's their file section)

        void parseFiles(); // complete _params list
        virtual void interpretParam(const std::string section, const std::string &param); //Child implementation: interpret the param -> Make a regex on the param and call the right method about this param
        void interpretParamInList(); //interpret the last list elem: call interpretParam
        void interpretParamAtIndex(const size_t &index); //interpret list elem at index: call interpretParam
        void interpretParamInSection(const std::string &section); // interpret a param in section 'section'
        void interpretParamsInSection(const std::string &section); // interpret all params in section 'section'
        void interpretParams(); // Loop and depop all elems of the list for interpretation

        void popParam(); // 
        void popParam(const std::string &section, const std::string &param);

    protected:
        std::list<std::pair<std::string /*The section of the file*/, std::string /*The content*/>> _params;

    private:
        const static inline std::string MapFileName = "oui"; // where the map is saved
        const static inline std::string HighScoreFileName = "oui"; // where highscore are saved
        const static inline std::string CharactersFileName = "oui"; // Parse it to get player character score and some other params
};
