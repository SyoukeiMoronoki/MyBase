#pragma once

#include <string>
#include <vector>

#include "ParserContext.h"

class Parser;

class Parser
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  Parser();
  virtual ~Parser();

  // =================================================================
  // Methods
  // =================================================================
public:
  virtual bool Eat(const std::string& token, ParserContext* context) = 0;

  void AddChild(Parser* child);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE void SetParent(Parser* parent)
  {
    this->parent_ = parent;
  }

  GG_INLINE Parser* GetParent()
  {
    return this->parent_;
  }

  // =================================================================
  // Data Members
  // =================================================================
private:
  Parser* parent_;
  std::vector<Parser*> children_;

};