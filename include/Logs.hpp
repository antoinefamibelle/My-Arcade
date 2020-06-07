/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Logs
** BONUS :
** g++ -D foo=true // c'est jsute incroyable
** log level :
** - notice -> tu affiche les logs
** - warning -> tu afficher les logs en warning
** - error -> tu throw une d'erreur
** - fatalerror -> tu throw une fatale erreur
** - definir des stream selon le lvl de log
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>

const std::string ARCADE_FILE = "arcade.txt";

namespace log {
    class LogsError : public std::exception
    {
        public:
            LogsError(std::string const &message, std::string const &funcName = "Unknow") noexcept : _message(message), _funcName(funcName) {};
            virtual ~LogsError() = default;

            std::string const &getFuncName() const noexcept { return _funcName; };
            virtual const char *what() const noexcept override { return _message.c_str(); };
        private:
            std::string _message; // exception.what() to write when catching the error
            std::string _funcName;
    };

    class Logs {
        public:

            Logs(const std::string &fileName = ""): _aFile(), _fileName(fileName) { 
                if (writeFile == true)
                    _aFile.open(fileName, std::ofstream::out | std::ofstream::app); 
                };
            ~Logs() = default;

            std::ofstream &getStreamFile() noexcept { return _aFile; };
            void setStreamFile(const std::string &fileName) noexcept {
                if (writeFile == true)
                    _aFile.open(fileName);
            };

            template <typename T>
            void output(const T &aLog, const std::string &message = "") const noexcept
            {
                std::cout << message << aLog << std::endl;
            }

            template <typename T>
            void error(const T &aLog, const std::string &message = "") const noexcept
            {
                std::cerr << message << aLog << std::endl;
            }
            
            template <typename T>
            void stream(std::ofstream &stream, const T &aLog, const std::string &message = "") const noexcept
            {
                if (stream.is_open()) {
                    stream << message << aLog << std::endl;
                }
            }

            template <typename T>
            void file(const T &aLog, const std::string &message = "") noexcept
            {
                if (writeFile == true) {
                    if (_aFile.is_open()) {
                        _aFile << message << aLog << std::endl;
                    }
                    else {
                        error("File not open", "logFile function: ");
                    }
                }
                else {
                    error(aLog, message);
                }
            }

            void cleanFile() noexcept
            {
                std::ofstream ofs;
                
                if (writeFile == true) {
                    ofs.open(_fileName, std::ofstream::out | std::ofstream::trunc);
                    ofs.close();
                }
            }

        private:
            std::ofstream _aFile;
            std::string _fileName;
            static inline bool writeFile = false;
    };
}