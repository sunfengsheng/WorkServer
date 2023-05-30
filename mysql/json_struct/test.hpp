#ifndef TEST_H
#define TEST_H

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/data/mapping/type/List.hpp"
#include "oatpp/core/data/mapping/type/Primitive.hpp"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class Test : public oatpp::DTO {
  
  DTO_INIT(Test, DTO)
  
  DTO_FIELD(String, field_string, "string-field-name-qualifier");
  DTO_FIELD(Int32, field_int32, "int32-field-name-qualifier");
  DTO_FIELD(Int64, field_int64);
  DTO_FIELD(Float32, field_float32);
  DTO_FIELD(Float64, field_float64);
  DTO_FIELD(Boolean, field_boolean);
  
  DTO_FIELD(List<String>, field_list_string) = {};
  DTO_FIELD(List<Int32>, field_list_int32) = {};
  DTO_FIELD(List<Int64>, field_list_int64) = {};
  DTO_FIELD(List<Float32>, field_list_float32) = {};
  DTO_FIELD(List<Float64>, field_list_float64) = {};
  DTO_FIELD(List<Boolean>, field_list_boolean) = {};
  

  // DTO_FIELD(Vector<String>, field_vector);
  // DTO_FIELD(Fields<String>, field_fields);
  // DTO_FIELD(UnorderedFields<String>, field_unordered_fields);
  // DTO_FIELD(Object<Test>, obj1);
  
};

class RecUserInfo : public oatpp::DTO{
    DTO_INIT(RecUserInfo, DTO)
    DTO_FIELD(String, WXId, "WXId");
};

class RespUserInfo : public oatpp::DTO{
    DTO_INIT(RespUserInfo, DTO)
    DTO_FIELD(String, WXId, "WXId");
    DTO_FIELD(String, Name, "Name");
    DTO_FIELD(Int32, AttentionCount, "AttentionCount");
    DTO_FIELD(Int32, LikeCount, "LikeCount");
};

class RespUploadWork : public oatpp::DTO{
    DTO_INIT(RespUploadWork, DTO)
    DTO_FIELD(String, WXId, "WXId");
    DTO_FIELD(String, Content, "Content");
    DTO_FIELD(String, Title, "Title");
    DTO_FIELD(Vector<String>, Images, "Images");
    DTO_FIELD(Vector<String>, Reviews, "Reviews");
};

#endif // HANDLER_H