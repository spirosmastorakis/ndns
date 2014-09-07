/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014, Regents of the University of California.
 *
 * This file is part of NDNS (Named Data Networking Domain Name Service).
 * See AUTHORS.md for complete list of NDNS authors and contributors.
 *
 * NDNS is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NDNS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NDNS, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NDNS_NDNS_LABEL_HPP
#define NDNS_NDNS_LABEL_HPP

#include "ndns-enum.hpp"

#include <ndn-cxx/name.hpp>
#include <ndn-cxx/interest.hpp>

#include <string>

namespace ndn {
namespace ndns {
namespace label {

/**
 * @brief NDNS iterative query type
 */

const name::Component NdnsIterativeQuery("NDNS");

/**
 * @brief NDNS recursive query type
 */
const name::Component NdnsRecursiveQuery("NDNS-R");

/**
 * @brief NDNS ID-CERT query type
 */
const name::Component NdnsCertQuery("KEY");

/////////////////////////////////////////////

/**
 * @brief label of forwarding hint
 * @todo not support forwarding hint yet, for future use
 */
const name::Component ForwardingHintLabel("\xF0.");

/**
 * @brief label of update message, located at the last component in Interest name
 */
const name::Component NdnsUpdateLabel("UPDATE");

//////////////////////////////////////////////

/**
 * @brief NS resource record type
 */
const name::Component NsRrType("NS");

/**
 * @brief ID-CERT resource record type
 */
const name::Component CertRrType("ID-CERT");

//////////////////////////////////////////

/**
 * @brief result of Matching. version only works when matching a Interest Name
 */
struct MatchResult
{
  Name rrLabel;
  name::Component rrType;
  name::Component version;
};

/**
 * @brief match the Interest (NDNS query, NDNS update) name
 *
 * @param[in] interest Interest to parse
 * @param[in] hint Forwarding hint that is part of the Interest
 *            (only the length will be taken into account)
 * @param[in] zone Zone that the Interest is related to
 *            (only the length will be taken into account)
 * @param[out] result The matching result
 * @return true if match succeeds, or false
 */
bool
matchName(const Interest& interest,
           const Name& hint, const Name& zone,
           MatchResult& result);

/**
 * @brief match the Data (NDNS query response, NDNS update response) name
 *
 * @param[in] data Data to parse
 * @param[in] hint Forwarding hint that is part of the Data
 *            (only the length will be taken into account)
 * @param[in] zone Zone that the Data is related to
 *            (only the length will be taken into account)
 * @param[out] result The matching result
 * @return true if match succeeds, or false
 */
bool
matchName(const Data& data,
          const Name& hint, const Name& zone,
          MatchResult& result);

} // namespace label
} // namespace ndns
} // namespace ndn

#endif // NDNS_NDNS_LABEL_HPP
