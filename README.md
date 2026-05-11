<section>
  <h2 align="left">🧪 <u>Testing Overview (CUnit)</u></h2>
  
  <p>
    The system's reliability is ensured through a comprehensive <b>suite of automated unit tests</b> using the <b>CUnit framework</b>. The test suite is meticulously designed to handle edge cases and ensure <i>memory-safe execution</i>.
  </p>

  <h3><b>Key Validation Areas:</b></h3>

  <ul>
    <li>
      <b>Data Integrity & Input Validation:</b> Ensures all user data (Names, Ages, Dates of Birth) adheres to expected formats and logical constraints. This includes handling complex <u>date validations</u> such as leap years and varying month lengths.
    </li>
    <li>
      <b>Logical Validation:</b> Validates the logical relationship between different user attributes. For example, the system cross-references a <i>user's age</i> against their <i>educational status</i> to prevent impossible combinations.
    </li>
    <li>
      <b>Authentication & Security:</b> Tests the robustness of the login mechanism by verifying successful logins, handling incorrect credentials gracefully, and explicitly <u>preventing the creation of duplicate accounts</u>.
    </li>
    <li>
      <b>System Capacity Constraints:</b> Verifies the system's behavior and stability when it reaches <b>maximum user capacity</b> or encounters boundary-level stress conditions.
    </li>
  </ul>
</section>
