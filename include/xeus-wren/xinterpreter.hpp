/***************************************************************************
* Copyright (c) 2021,                                          
*                                                                          
* Distributed under the terms of the BSD 3-Clause License.                 
*                                                                          
* The full license is in the file LICENSE, distributed with this software. 
****************************************************************************/


#ifndef XEUS_WREN_INTERPRETER_HPP
#define XEUS_WREN_INTERPRETER_HPP

#ifdef __GNUC__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wattributes"
#endif

#include <string>
#include <memory>
#include <map>

#include "nlohmann/json.hpp"
#include "wrenbind17/wrenbind17.hpp"

#include "xeus_wren_config.hpp"
#include "xeus/xinterpreter.hpp"


extern "C" {
#include <wren.h>
}

namespace nl = nlohmann;

namespace xeus_wren
{


    class XEUS_WREN_API interpreter : public xeus::xinterpreter
    {
    public:

        interpreter();
        virtual ~interpreter();

    protected:

        void configure_impl() override;

        nl::json execute_request_impl(int execution_counter,
                                      const std::string& code,
                                      bool silent,
                                      bool store_history,
                                      nl::json user_expressions,
                                      bool allow_stdin) override;

        nl::json complete_request_impl(const std::string& code, int cursor_pos) override;

        nl::json inspect_request_impl(const std::string& code,
                                      int cursor_pos,
                                      int detail_level) override;

        nl::json is_complete_request_impl(const std::string& code) override;

        nl::json kernel_info_request_impl() override;

        void shutdown_request_impl() override;


        void write_handler(const char* text);

        void error_handler(WrenErrorType errorType,
             const char* module, const int line,
             const char* msg);



        friend void write_fn(WrenVM* vm, const char* text);
        friend void error_fn(WrenVM* vm, WrenErrorType errorType,
                 const char* module, const int line,
                 const char* msg);

    public:
        std::map<
            std::string, /*module*/
            std::map< 
                std::string, /* cls_name */
                std::map<
                    std::string, /* method name / signature */
                    WrenForeignMethodFn
                >
            >
        > m_forein_methods;

        WrenVM* p_vm;

        wrenbind17::VM m_vm;
        
    };
}

#ifdef __GNUC__
    #pragma GCC diagnostic pop
#endif

#endif
