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

#ifndef NDNS_TESTS_UNIT_DATABASE_TEST_DATA_HPP
#define NDNS_TESTS_UNIT_DATABASE_TEST_DATA_HPP

#include "daemon/db-mgr.hpp"
#include "clients/response.hpp"
#include "clients/query.hpp"
#include "validator.hpp"

#include "../boost-test.hpp"

#include <ndn-cxx/security/key-chain.hpp>
#include <boost/filesystem.hpp>

namespace ndn {
namespace ndns {
namespace tests {

class DbTestData
{
public:
  static const boost::filesystem::path TEST_DATABASE;
  static const Name TEST_IDENTITY_NAME;
  static const boost::filesystem::path TEST_CERT;

  DbTestData();

  ~DbTestData();

private:
  void
  addRrset(Zone& zone, const Name& label, const name::Component& type,
                       const time::seconds& ttl, const name::Component& version,
                       const name::Component& qType, NdnsType ndnsType, const std::string& msg);
public:
  Name m_certName;
  Name m_keyName;
  std::vector<Zone>  m_zones;
  std::vector<Rrset> m_rrsets;

  bool doesTestIdentityExist;
  DbMgr m_session;
  KeyChain m_keyChain;
};

} // namespace tests
} // namespace ndns
} // namespace ndn

#endif // NDNS_TESTS_UNIT_DATABASE_TEST_DATA_HPP