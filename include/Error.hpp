/*
** EPITECH PROJECT, 2020
** OOP_aracde_2019
** File description:
** Error
*/

#pragma once

#include <string>

class ArcadeErrors : public std::exception
{
    public:
        ArcadeErrors(std::string const &message,
                std::string const &functionPart = "Unknown") noexcept : _message(message), _functionPart(functionPart) {};
        virtual ~ArcadeErrors() = default;

        std::string const &getFunctionPart() const noexcept { return _functionPart; };
        virtual const char *what() const noexcept override { return _message.c_str(); };

    private:
        std::string _message; // exception.what() to write when catching the error
        std::string _functionPart; // for example -> getName, etc...
};

class GameError : public ArcadeErrors
{
    public:
        GameError(std::string const &message,
                std::string const &functionPart = "Unknown") noexcept : ArcadeErrors("Game Error" + message, functionPart) {};
};

class GraphicalError : public ArcadeErrors
{
    public:
        GraphicalError(std::string const &message,
                std::string const &functionPart = "Unknown") noexcept : ArcadeErrors("Graphical Error: " + message, functionPart) {};
};

class ExecutionError : public ArcadeErrors
{
    public:
        ExecutionError(std::string const &message) noexcept : ArcadeErrors("Execution Error: "+ message, "Execution") {};
};

class FileError: public ArcadeErrors
{
    public:
        FileError(std::string const &message) noexcept : ArcadeErrors("File Error: " + message, "FileContent") {};
};
