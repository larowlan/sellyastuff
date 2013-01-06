<?php
/**
 * @file
 * Provides default payment rules needed by the site
 * @copyright Copyright(c) 2011 Lee Rowlands
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Lee Rowlands larowlan at previousnext dot com dot au
 */

/**
 * Implementation of hook_default_rules_configuration().
 */
function sellyastuff_default_rules_configuration() {
  $items = array();
  $items['sell_ya_stuff_payment'] = entity_import('rules_config', '{ "sell_ya_stuff_payment" : {
      "LABEL" : "Sell ya stuff Payment",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : [ "commerce_payment_methods" ],
      "DO" : [
        { "commerce_payment_enable_nab_transact" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : { "value" : {
                "method_id" : "nab_transact",
                "settings" : {
                  "commerce_nab_currency" : "AUD",
                  "commerce_nab_transact_po_prefix" : "",
                  "commerce_nab_transact_xml_settings" : {
                    "commerce_nab_xml_merchant_id" : "ABC0001",
                    "commerce_nab_xml_password" : "123456",
                    "commerce_nab_xml_mode" : "test",
                    "commerce_nab_xml_txn_type" : "0"
                  }
                }
              }
            }
          }
        }
      ]
    }
  }');
  return $items;
}
