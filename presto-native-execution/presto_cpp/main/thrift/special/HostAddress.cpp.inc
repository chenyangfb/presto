/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

void toThrift(const facebook::presto::protocol::HostAddress& proto, HostAddress& thrift) {
  std::vector<std::string> parts;
  folly::split(":", proto, parts);
  if (parts.size() == 2) {
    thrift.host_ref() = parts[0];
    thrift.port_ref() = std::stoi(parts[1]);
  }
}
void fromThrift(const HostAddress& thrift, facebook::presto::protocol::HostAddress& proto) {
  std::string hostAddressStr =
    *thrift.host_ref() + "." +
    std::to_string(*thrift.port_ref());
  fromThrift(hostAddressStr, proto);
}
