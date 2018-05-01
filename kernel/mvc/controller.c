/*
  +----------------------------------------------------------------------+
  | CSpeed framework                                                     |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:Josin<774542602@qq.com|www.supjos.cn>                         |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_cspeed.h"

#include "kernel/di/di.h"
#include "kernel/mvc/controller.h"
#include "kernel/tool/component.h"

/*{{{*/
ZEND_BEGIN_ARG_INFO_EX(arginfo_cspeed_controller_construct, 0, 0, 0)
ZEND_END_ARG_INFO()
/*}}}*/

CSPEED_METHOD(Controller, __construct)/*{{{ proto Controller::__construct() */
{
    
}/*}}}*/

static const zend_function_entry cspeed_controller_functions[] = { /*{{{*/
    CSPEED_ME(
      Controller, 
      __construct, 
      arginfo_cspeed_controller_construct, 
      ZEND_ACC_PUBLIC
    )
    PHP_FE_END
};/*}}}*/

CSPEED_INIT(controller) /*{{{*/
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, 
      "Cs\\mvc", 
      "Controller", 
      cspeed_controller_functions
    );
    cspeed_controller_ce = zend_register_internal_class(&ce);

    /* Event feature */
    zend_do_inheritance(cspeed_controller_ce, cspeed_component_ce);

    zend_declare_property_null(
      cspeed_controller_ce, 
      CSPEED_STRL(CSPEED_DI_INSTANCE), 
      ZEND_ACC_PUBLIC
    );
    zend_declare_property_null(
      cspeed_controller_ce, 
      CSPEED_STRL(CSPEED_VIEW_INSTANCE), 
      ZEND_ACC_PUBLIC
    );
    zend_declare_property_null(
      cspeed_controller_ce, 
      CSPEED_STRL(CSPEED_ROUTER_INSTANCE), 
      ZEND_ACC_PUBLIC
    );

    zend_declare_class_constant_string(
      cspeed_controller_ce, 
      CSPEED_STRL(EVENT_BEFORE_ACTION), 
      EVENT_BEFORE_ACTION
    );
    zend_declare_class_constant_string(
      cspeed_controller_ce, 
      CSPEED_STRL(EVENT_AFTER_ACTION), 
       EVENT_AFTER_ACTION
    );
}/*}}}*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
