module Styles = {
  open ReactDOMRe;

  let container =
    Style.make(
      ~alignItems="center",
      ~display="flex",
      ~fontFamily="sans-serif",
      ~justifyContent="center",
      (),
    );
};

[@react.component]
let make = (~message) => {
  let (messageVisible, setMessageVisible) = React.useState(() => false);

  let handleClick = _event =>
    setMessageVisible(messageVisible => !messageVisible);

  <div style=Styles.container>
    <h1 onClick=handleClick>
      {messageVisible ? React.string(message) : React.string("Click me!")}
    </h1>
  </div>;
};
