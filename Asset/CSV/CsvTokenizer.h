#pragma once

class CsvToken
{
  // =================================================================
  // Factory Method
  // =================================================================
public:
  static CsvToken Create(const std::string& str);

  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  CsvToken(const std::string& str);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  T_INT32 ToInt32() const;
  T_INT64 ToInt64() const;
  T_FLOAT ToFloat() const;
  T_DOUBLE ToDouble() const;
  const std::string& ToString() const;
  
  // =================================================================
  // Data Member
  // =================================================================
private:
  const std::string str_;
};

class CsvTokenizer
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  CsvTokenizer(const std::string& str);
  CsvTokenizer(const CsvTokenizer& other);
  ~CsvTokenizer();

  // =================================================================
  // Method
  // =================================================================
public:
  void Reset();
  bool HasNextToken();
  const CsvToken& NextToken();

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE std::vector<CsvToken>::iterator Begin()
  {
    return this->tokens_.begin();
  }

  GG_INLINE std::vector<CsvToken>::iterator End()
  {
    return this->tokens_.end();
  }

  GG_INLINE size_t GetSize() const
  {
    return this->tokens_.size();
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  std::vector<CsvToken> tokens_;
  T_UINT16 now_token_index_;
};
