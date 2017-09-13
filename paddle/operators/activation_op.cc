/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#include "paddle/operators/activation_op.h"

// #define FILL_ACTIVATION_OP                                                  \
//  public:                                                                    \
//   using framework::OperatorWithKernel::OperatorWithKernel;                  \
//                                                                             \
//  protected:                                                                 \
//   void InferShape(const framework::InferShapeContext &ctx) const override { \
//     ctx.Output<framework::Tensor>("Y")->Resize(                             \
//         ctx.Input<framework::Tensor>("X")->dims());                         \
//   }

// #define FILL_ACTIVATION_GRAD_OP                                             \
//  public:                                                                    \
//   using framework::OperatorWithKernel::OperatorWithKernel;                  \
//                                                                             \
//  protected:                                                                 \
//   void InferShape(const framework::InferShapeContext &ctx) const override { \
//     ctx.Output<framework::Tensor>(framework::GradVarName("X"))              \
//         ->Resize(ctx.Input<framework::Tensor>("Y")->dims());                \
//   }

namespace paddle {
namespace operators {

class ActivationOp : public framework::OperatorWithKernel {
 public:
  using framework::OperatorWithKernel::OperatorWithKernel;

 protected:
  void InferShape(const framework::InferShapeContext &ctx) const override {
    ctx.Output<framework::Tensor>("Y")->Resize(
        ctx.Input<framework::Tensor>("X")->dims());
  }
};

class ActivationOpGrad : public framework::OperatorWithKernel {
 public:
  using framework::OperatorWithKernel::OperatorWithKernel;

 protected:
  void InferShape(const framework::InferShapeContext &ctx) const override {
    ctx.Output<framework::Tensor>(framework::GradVarName("X"))
        ->Resize(ctx.Input<framework::Tensor>("Y")->dims());
  }
};

// class SigmoidOp : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_OP
// };

class SigmoidOpMaker : public framework::OpProtoAndCheckerMaker {
 public:
  SigmoidOpMaker(framework::OpProto *proto,
                 framework::OpAttrChecker *op_checker)
      : OpProtoAndCheckerMaker(proto, op_checker) {
    AddInput("X", "Input of Sigmoid operator");
    AddOutput("Y", "Output of Sigmoid operator");
    AddComment("Sigmoid activation operator");
  }
};

// class SigmoidOpGrad : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_GRAD_OP
// };

// class ExpOp : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_OP
// };

class ExpOpMaker : public framework::OpProtoAndCheckerMaker {
 public:
  ExpOpMaker(framework::OpProto *proto, framework::OpAttrChecker *op_checker)
      : OpProtoAndCheckerMaker(proto, op_checker) {
    AddInput("X", "Input of Exp operator");
    AddOutput("Y", "Output of Exp operator");
    AddComment("Exp activation operator");
  }
};

// class ExpOpGrad : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_GRAD_OP
// };

// class ReluOp : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_OP
// };

class ReluOpMaker : public framework::OpProtoAndCheckerMaker {
 public:
  ReluOpMaker(framework::OpProto *proto, framework::OpAttrChecker *op_checker)
      : OpProtoAndCheckerMaker(proto, op_checker) {
    AddInput("X", "Input of Relu operator");
    AddOutput("Y", "Output of Relu operator");
    AddComment("Relu activation operator");
  }
};

// class ReluOpGrad : public framework::OperatorWithKernel {
//   FILL_ACTIVATION_GRAD_OP
// };

}  // namespace operators
}  // namespace paddle

namespace ops = paddle::operators;
REGISTER_OP(sigmoid, ops::ActivationOp, ops::SigmoidOpMaker, sigmoid_grad,
            ops::ActivationOpGrad);
REGISTER_OP_CPU_KERNEL(
    sigmoid,
    ops::ActivationKernel<paddle::platform::CPUPlace, float, ops::Sigmoid>);
REGISTER_OP_CPU_KERNEL(sigmoid_grad,
                       ops::ActivationGradKernel<paddle::platform::CPUPlace,
                                                 float, ops::SigmoidGrad>);

REGISTER_OP(exp, ops::ActivationOp, ops::ExpOpMaker, exp_grad,
            ops::ActivationOpGrad);
REGISTER_OP_CPU_KERNEL(
    exp, ops::ActivationKernel<paddle::platform::CPUPlace, float, ops::Exp>);
REGISTER_OP_CPU_KERNEL(
    exp_grad,
    ops::ActivationGradKernel<paddle::platform::CPUPlace, float, ops::ExpGrad>);

// REGISTER_OP(relu, ops::ActivationOp, ops::ReluOpMaker, relu_grad,
// ops::ActivationOpGrad);
// REGISTER_OP_CPU_KERNEL(relu,
//                        ops::ReluKernel<paddle::platform::CPUPlace, float,
//                        ops::Relu>);
// REGISTER_OP_CPU_KERNEL(relu_grad,
//                        ops::ReluGradKernel<paddle::platform::CPUPlace, float,
//                        ops::ReluGrad>);
